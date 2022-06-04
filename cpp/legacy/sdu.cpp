#include <iostream>
#include <string>


using namespace std;

/* sdu �� pdu ��ص����ݽṹ */
//��Ҫ����Ϊҵ�����ݷ���USCH�ķ�Ƭ�����DSCH�������Ƭ

typedef enum {
	USCH_FLAG_UNFRAG = 0x00,	//û�н��з�Ƭ
	USCH_FLAG_FRAG_START = 0x01,	//��һ����Ƭ
	USCH_FLAG_FRAG_NEXT = 0x02,	//�������з�Ƭ
	USCH_FLAG_FRAG_STOP = 0x03,	//���һ����Ƭ
} data_type_t;

typedef enum {
	undo = 0,
	done = 1,
	repet = 2
} return_state;

typedef struct {
	uint8_t				flag : 2;
	uint8_t				sseq : 6;
	uint8_t				priority : 1;
	uint8_t				pseq : 7;
	uint8_t				size;
} usch_data_head_t;

//�����˵�pdu��֮������Ϣ���з���ȥ��·�ɣ�����Ͳ���Ҫcid��sseq��
typedef struct sdu_item_t {
	//uint16_t cid;
	//uint16_t offset;
	uint16_t len;
	uint8_t buf[1400];	//sduЭ�鶨����Ϊ1400B
} sdu_item_t;

typedef struct pdu_item_t {
	struct pdu_item_t * prev;
	struct pdu_item_t * next;
	uint8_t				used;
	usch_data_head_t	pdu_head;		//����������pseq������룬β�巨���ٶȸ���
	uint8_t				pdu_buf[250];	//�������pdu��С����̬���� [250];	//256 - 3 - 3 - 2 ---
} pdu_item_t;

typedef struct pdu_queue_t {
	struct pdu_queue_t * prev;
	struct pdu_queue_t * next;
	uint8_t used;
	uint8_t	nums;
	uint8_t	sseq;			//��������Ҫ����cidȻ���ٿ�sseq
	uint8_t pseq_start;
	uint8_t pseq_stop;
	//uint16_t	size;
	//uint8_t		done;	//���һ����
	uint32_t	time;	//��¼���һ�β���pdu��ʱ�䣬����10sδ��Ӧ˵���з�Ƭ��ʧ����pdu_queueʧЧ����գ�����ǲ��ش��ı�����
	pdu_item_t	dummy;	//�ڱ�ͷ�ڵ�
} pdu_queue_t;

typedef struct sdu_queue_t {
	struct sdu_queue_t * prev;
	struct sdu_queue_t * next;
	uint8_t used;
	//uint8_t	nums;	//��������о�ûʲô��
	//uint16_t size;
	pdu_queue_t dummy;	//�ڱ�ͷ�ڵ�
} sdu_queue_t;

#define	PDU_ITEM_POOL_SIZE	10000
#define PDU_QUEUE_POOL_SIZE	1000
#define SDU_QUEUE_POOL_SIZE 100

#define SDU_ITEM_POOL_SIZE	10

sdu_item_t sdu_item_pool[SDU_ITEM_POOL_SIZE];


pdu_item_t	pdu_item_pool[PDU_ITEM_POOL_SIZE];
pdu_queue_t	pdu_queue_pool[PDU_QUEUE_POOL_SIZE];
sdu_queue_t	sdu_queue_pool[SDU_QUEUE_POOL_SIZE];

//pdu_item_t��غ���
pdu_item_t* get_pdu_item() {
	for (int i = 0; i < PDU_ITEM_POOL_SIZE; i++) {
		if (pdu_item_pool[i].used == 0) {
			return &pdu_item_pool[i];
		}
	}
	return NULL;
}

void init_pdu_item(pdu_item_t* pdu_item) {
	pdu_item->next = NULL;
	pdu_item->prev = NULL;
}




//pdu_queue_t��غ���
pdu_queue_t* get_pdu_queue() {
	for (int i = 0; i < PDU_QUEUE_POOL_SIZE; i++) {
		if (pdu_queue_pool[i].used == 0) {
			return &pdu_queue_pool[i];
		}
	}
	return NULL;
}

void init_pdu_queue(pdu_queue_t* pdu_queue) {
	pdu_queue->next = NULL;
	pdu_queue->prev = NULL;
	pdu_queue->nums = 0;
	pdu_queue->pseq_start = 0;
	pdu_queue->pseq_stop = 0;
	pdu_queue->dummy.next = NULL;
	pdu_queue->dummy.prev = NULL;
}

pdu_queue_t* search_pdu_queue(sdu_queue_t* sdu_queue, uint8_t sseq) {
	pdu_queue_t* ptr = &sdu_queue->dummy;
	while (ptr->next != NULL) {
		if (ptr->next->sseq == sseq) {
			return ptr->next;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void delete_pdu_queue(pdu_queue_t* pdu_queue) {
	pdu_queue->used = 0;
	if (pdu_queue->next != NULL) pdu_queue->next->prev = pdu_queue->prev;
	if (pdu_queue->prev != NULL) pdu_queue->prev->next = pdu_queue->next;
}



void gen_sdu_item(pdu_queue_t* pdu_queue, sdu_item_t* sdu_item) {
	if (sdu_item == NULL) return;
	sdu_item->len = 0;
	pdu_item_t* ptr = &pdu_queue->dummy;
	while (ptr->next != NULL) {
		memcpy(sdu_item->buf + sdu_item->len, ptr->next->pdu_buf, ptr->next->pdu_head.size);
		sdu_item->len += ptr->next->pdu_head.size;
		ptr->next->used = 0;
		ptr = ptr->next;
	}
	//��sdu���ķ���ȥ
	for (int i = 0; i < sdu_item->len; i++) {
		cout << sdu_item->buf[i];
	}
	//��sdu_queue��ɾ��pdu_queue
	delete_pdu_queue(pdu_queue);
}


uint8_t insert_pdu_item(pdu_queue_t* pdu_queue, pdu_item_t* pdu_item) {
	//����pseq�������
	pdu_item_t* ptr = &pdu_queue->dummy;
	//ǰ�巨
	//Ѱ�Ҳ����
	while (ptr->next != NULL && pdu_item->pdu_head.pseq > ptr->next->pdu_head.pseq) {
		ptr = ptr->next;
	}
	if (ptr->next != NULL && pdu_item->pdu_head.pseq == ptr->next->pdu_head.pseq) {
		return repet;	//�ظ�pseq
	}
	//����ڵ�
	pdu_item->next = ptr->next;
	pdu_item->prev = ptr;
	if (pdu_item->next != NULL) pdu_item->next->prev = pdu_item;
	pdu_item->prev->next = pdu_item;
	pdu_item->used = 1;
	//ͳ����Ϣ
	if (pdu_item->pdu_head.flag == USCH_FLAG_FRAG_START) pdu_queue->pseq_start = pdu_item->pdu_head.pseq;
	if (pdu_item->pdu_head.flag == USCH_FLAG_FRAG_STOP)	pdu_queue->pseq_stop = pdu_item->pdu_head.pseq;
	pdu_queue->time = 0;//�������ʱ���������ʵ��pdu_queue->pseq_start != -1 && 
	pdu_queue->nums++;
	//cout << (int)pdu_queue->pseq_start << " " << (int)pdu_queue->pseq_stop << " " << (int)pdu_queue->nums << endl;
	if (pdu_queue->pseq_stop != 0 && pdu_queue->nums == (pdu_queue->pseq_stop + 0x7f - pdu_queue->pseq_start) % 0x7f + 1) {	//pseq��һ��7bitѭ��ʹ�õ���
		//pdu_queue->done = 1;//���������һ����
		//����Ҫ��ʼ����sdu���ķ���ȥ�ˣ�Ȼ�����ɾ��pdu����
		gen_sdu_item(pdu_queue, &sdu_item_pool[0]);
	}
	return done;
}


void delete_pdu_item(pdu_queue_t* pdu_queue, pdu_item_t* pdu_item) {
	pdu_item->used = 0;
	if (pdu_item->next != NULL) pdu_item->next->prev = pdu_item->prev;
	if (pdu_item->prev != NULL) pdu_item->prev->next = pdu_item->next;
	pdu_queue->nums--;
}


void print_pdu_queue(pdu_queue_t* pdu_queue) {
	pdu_item_t* ptr = &pdu_queue->dummy;
	while (ptr->next != NULL) {
		printf("%d ->", ptr->next->pdu_head.pseq);
		ptr = ptr->next;
	}
	printf("\n");
}

uint8_t insert_pdu_queue(sdu_queue_t* sdu_queue, pdu_queue_t* pdu_queue) {
	//����sseq�������
	pdu_queue_t* ptr = &sdu_queue->dummy;
	//ǰ�巨
	//Ѱ�Ҳ����
	while (ptr->next != NULL && pdu_queue->sseq > ptr->next->sseq) {
		ptr = ptr->next;
	}
	if (ptr->next != NULL && pdu_queue->sseq == ptr->next->sseq) {
		return repet;	//�ظ�pseq
	}
	//����ڵ�
	pdu_queue->next = ptr->next;
	pdu_queue->prev = ptr;
	if (pdu_queue->next != NULL) pdu_queue->next->prev = pdu_queue;
	pdu_queue->prev->next = pdu_queue;
	pdu_queue->used = 1;
	return done;
}


//sdu_queue_t��غ���
sdu_queue_t* get_sdu_queue() {
	for (int i = 0; i < SDU_QUEUE_POOL_SIZE; i++) {
		if (sdu_queue_pool[i].used == 0) {
			return &sdu_queue_pool[i];
		}
	}
	return NULL;
}

void init_sdu_queue(sdu_queue_t* sdu_queue) {
	sdu_queue->next = NULL;
	sdu_queue->prev = NULL;
	sdu_queue->dummy.next = NULL;
	sdu_queue->dummy.prev = NULL;
}





void print_sdu_queue(sdu_queue_t* sdu_queue) {
	pdu_queue_t* ptr = &sdu_queue->dummy;
	while (ptr->next) {
		print_pdu_queue(ptr->next);
		ptr = ptr->next;
	}
}




//ÿ��cid����һ��pdu_queue��������ss_online������


int main() {
	sdu_queue_t* this_sdu_queue = get_sdu_queue();
	init_sdu_queue(this_sdu_queue);
	uint8_t a[10][20] = {
		{ 1, 4, 5, 6, 8, 9, 80, 6, 5, 3, 6, 4, 7, 89, 56, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 89, 56, 80, 6, 5, 3, 6, 4, 7, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 68, 6, 5, 3, 6, 4, 7, 83, 56, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 35, 6, 5, 3, 6, 4, 7, 57, 56, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 5, 3, 6, 4, 7, 89, 56, 6, 8, 9, 80, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 53, 6, 5, 3, 6, 4, 7, 36, 56, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 13, 6, 5, 3, 6, 4, 7, 16, 56, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 13, 6, 5, 3, 6, 4, 7, 83, 56, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 34, 6, 5, 3, 6, 4, 7, 58, 56, 76, 78, 35, 24, 31 },
		{ 1, 4, 5, 6, 8, 9, 36, 6, 5, 3, 6, 4, 7, 43, 56, 76, 78, 35, 24, 31 }
	}; 

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			pdu_item_t* cur = get_pdu_item();
			init_pdu_item(cur);
			cur->pdu_head.sseq = i;
			cur->pdu_head.pseq = a[i][j];
			pdu_queue_t* cur_queue = search_pdu_queue(this_sdu_queue, i);
			if (cur_queue == NULL) {
				cur_queue = get_pdu_queue();
				init_pdu_queue(cur_queue);
				cur_queue->sseq = i;
				insert_pdu_queue(this_sdu_queue, cur_queue);
			}
			insert_pdu_item(cur_queue, cur);
		}
	}

	
	int a, b, c;
	char temp[100];
	while (cin >> a >> b >> c >> temp) {
		pdu_item_t* cur = get_pdu_item();
		init_pdu_item(cur);
		cur->pdu_head.sseq = a;
		cur->pdu_head.pseq = b;
		for (int i = 0; i < 100; i++) {
			if (temp[i] == 0) {
				cur->pdu_head.size = i;
				break;
			}
			cur->pdu_buf[i] = temp[i];
		}

		cur->pdu_head.flag = c;

		pdu_queue_t* cur_queue = search_pdu_queue(this_sdu_queue, a);
		if (cur_queue == NULL) {
			cur_queue = get_pdu_queue();
			init_pdu_queue(cur_queue);
			cur_queue->sseq = a;
			insert_pdu_queue(this_sdu_queue, cur_queue);
		}
		insert_pdu_item(cur_queue, cur);
	}
	for (int i = 0; i < 10; i++) {
		pdu_item_t* cur = get_pdu_item();
		init_pdu_item(cur);
		cur->pdu_head.sseq = 1;
		cur->pdu_head.pseq = i;
		cur->pdu_head.size = 2;
		cur->pdu_buf[0] = 'a' + i;
		cur->pdu_buf[1] = 'z' - i;
		if (i == 0) cur->pdu_head.flag = USCH_FLAG_FRAG_START;
		else if (i == 9) cur->pdu_head.flag = USCH_FLAG_FRAG_STOP;
		else cur->pdu_head.flag = USCH_FLAG_FRAG_NEXT;

		pdu_queue_t* cur_queue = search_pdu_queue(this_sdu_queue, 1);
		if (cur_queue == NULL) {
			cur_queue = get_pdu_queue();
			init_pdu_queue(cur_queue);
			cur_queue->sseq = 1;
			insert_pdu_queue(this_sdu_queue, cur_queue);
		}
		insert_pdu_item(cur_queue, cur);
	}
	for (int i = 0; i < 9; i++) {
		pdu_item_t* cur = get_pdu_item();
		init_pdu_item(cur);
		cur->pdu_head.sseq = 2;
		cur->pdu_head.pseq = i;
		cur->pdu_head.size = 2;
		cur->pdu_buf[0] = 'a' + i;
		cur->pdu_buf[1] = 'z' - i;
		if (i == 0) cur->pdu_head.flag = USCH_FLAG_FRAG_START;
		else if (i == 9) cur->pdu_head.flag = USCH_FLAG_FRAG_STOP;
		else cur->pdu_head.flag = USCH_FLAG_FRAG_NEXT;

		pdu_queue_t* cur_queue = search_pdu_queue(this_sdu_queue, 2);
		if (cur_queue == NULL) {
			cur_queue = get_pdu_queue();
			init_pdu_queue(cur_queue);
			cur_queue->sseq = 2;
			insert_pdu_queue(this_sdu_queue, cur_queue);
		}
		insert_pdu_item(cur_queue, cur);
	}

	print_sdu_queue(this_sdu_queue);
	system("pause");
	return 0;
}


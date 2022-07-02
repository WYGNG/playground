struct foo {

  int a;
  int b;

  bool operator==(const foo& rhs) /* *操作运算符重载**/

  {
    return( a == rhs.a) && (b == rhs.b);
  }
};

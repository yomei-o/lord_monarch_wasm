/* 1000:91d1 */

undefined4 FUN_1000_91d1(void)

{
  byte bVar1;
  uint uVar2;
  byte *unaff_SI;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  undefined2 in_stack_00000034;
  undefined2 in_stack_00000038;
  
  while( true ) {
    *(undefined2 *)0x3bd4 = 0;
    *(undefined2 *)0x3bd6 = 0;
    *(undefined2 *)0xc52c = 0;
    *(undefined2 *)0x32bf = 0;
    *(undefined2 *)0x3bc2 = 0xffff;
    func_0x0001c9da();
    FUN_1000_840b();
    func_0x0001c981();
    FUN_1000_5a6c();
    func_0x0001c9f8();
    func_0x0001ca10();
    func_0x0001c993();
    func_0x0001c9ad();
    func_0x00016dbc();
    FUN_1000_2406();
    FUN_1000_2425();
    FUN_1000_5e09();
    FUN_1000_5a6c();
    func_0x00013991();
    FUN_1000_2425();
    FUN_1000_5a6c();
    func_0x00013991();
    uVar2 = FUN_1000_13f4();
    if (0x17ff < uVar2) break;
    FUN_1000_a120();
    FUN_1000_a27b();
    func_0x0001a4db();
    func_0x0001a857();
    bVar1 = FUN_1000_60ec();
    *unaff_SI = *unaff_SI ^ bVar1;
    unaff_SI = (byte *)0xa99b;
    func_0x00013130(unaff_CS);
    unaff_CS = 0x12e8;
  }
  FUN_1000_43b4();
  FUN_1000_43b4();
  FUN_1000_1460();
  return CONCAT22(in_stack_00000034,in_stack_00000038);
}



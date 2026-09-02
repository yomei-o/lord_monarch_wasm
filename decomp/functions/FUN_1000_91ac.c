/* 1000:91ac */

undefined4 FUN_1000_91ac(void)

{
  byte bVar1;
  uint uVar2;
  byte *unaff_SI;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  
  FUN_1000_9510();
  func_0x00019925();
  FUN_1000_9b7a();
  do {
    FUN_1000_a120();
    FUN_1000_a27b();
    func_0x0001a4db();
    func_0x0001a857();
    bVar1 = FUN_1000_60ec();
    *unaff_SI = *unaff_SI ^ bVar1;
    unaff_SI = (byte *)0xa99b;
    func_0x00013130(unaff_CS);
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
    unaff_CS = 0x12e8;
  } while (uVar2 < 0x1800);
  FUN_1000_43b4();
  FUN_1000_43b4();
  FUN_1000_1460();
  return 0x920a9210;
}



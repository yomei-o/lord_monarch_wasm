/* 1000:9171 */

/* WARNING: Instruction at (ram,0x000191cc) overlaps instruction at (ram,0x000191cb)
    */

undefined4 FUN_1000_9171(undefined2 param_1)

{
  byte bVar1;
  uint uVar2;
  byte *unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_DS;
  undefined2 in_FS;
  char in_SF;
  char in_OF;
  
  func_0x0001d3ed();
  FUN_1000_8d15();
  *(undefined2 *)0x3bc6 = 6;
  FUN_1000_2703();
  func_0x0001d40c(register0x00000010);
  FUN_1000_3be7();
  func_0x0001c98b();
  FUN_1000_60c1();
  func_0x00017477();
  *(undefined2 *)0xc560 = 0;
  if (in_OF == in_SF) {
    unaff_SI = unaff_SI + -1;
    *(undefined2 *)0x346a = 0xffff;
    *(undefined2 *)0x346e = 0xffff;
    FUN_1000_9239();
    FUN_1000_9510();
    param_1 = 0x91b2;
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
      param_1 = unaff_DI;
      func_0x00013130();
FUN_1000_91d1:
      *(undefined2 *)0x3bd4 = 0;
      *(undefined2 *)0x3bd6 = 0;
      *(undefined2 *)0xc52c = 0;
      *(undefined2 *)0x32bf = 0;
      *(undefined2 *)0x3bc2 = 0xffff;
      func_0x0001c9da();
      param_1 = 0x91e9;
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
    } while (uVar2 < 0x1800);
    FUN_1000_43b4();
    FUN_1000_43b4();
    FUN_1000_1460();
    return 0x920a9210;
  }
  func_0x0001d3e3();
  goto FUN_1000_91d1;
}



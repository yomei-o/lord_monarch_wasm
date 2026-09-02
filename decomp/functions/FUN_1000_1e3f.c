/* 1000:1e3f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00011e78) overlaps instruction at (ram,0x00011e76)
    */

void FUN_1000_1e3f(void)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  char cVar5;
  int in_AX;
  int iVar6;
  undefined2 in_CX;
  char cVar7;
  undefined2 in_DX;
  int unaff_BP;
  int *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool in_CF;
  
  cVar7 = (char)((uint)in_CX >> 8);
  if (in_CF) {
    uVar3 = in(in_DX);
    *unaff_DI = uVar3;
    *(char *)0x3075 = *(char *)0x3075 - (char)in_DX;
    FUN_1000_7767();
    unaff_SI = (int *)0x1233;
    uVar4 = FUN_1000_4516();
    puVar2 = (undefined1 *)((int)unaff_DI + 3);
    *(undefined1 *)(unaff_DI + 1) = uVar4;
    unaff_DI = unaff_DI + 2;
    *puVar2 = uVar4;
    in_AX = func_0x000146ae();
    if ((char)in_AX != '\0') {
      func_0x000107d7();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    cVar7 = '8';
    *(int *)0xc55e = in_AX;
    *(int *)0x3bce = in_AX;
  }
  else {
    unaff_DS = (undefined2)((ulong)*(undefined4 *)((int)unaff_DI + unaff_BP + 0x3bce) >> 0x10);
  }
  iVar6 = in_AX + -1;
  *(int *)0x34c8 = iVar6;
  *(undefined1 *)0x328a = (char)iVar6;
  *(int *)0x3296 = iVar6;
  *(int *)0x3298 = iVar6;
  *(int *)0x329a = iVar6;
  *(undefined2 *)0x3bc2 = 0x95;
  func_0x0001fd7c(*(undefined2 *)((int)unaff_DI + 0x17),0x34);
  *(undefined2 *)0x3bc4 = 10;
  FUN_1000_5b9e();
  cVar5 = FUN_1000_077d();
  if ((char)(cVar5 + cVar7) != '\0') {
    func_0x0001c0a4();
    FUN_1000_079b();
    FUN_1000_5838();
    FUN_1000_91d1();
    FUN_1000_4f92();
    FUN_1000_6d2a();
    FUN_1000_5838();
    FUN_1000_4f92();
    FUN_1000_6d2a();
    func_0x0001fd2c();
    func_0x0001fd1a();
    func_0x0001fd46();
    piVar1 = unaff_SI;
    *piVar1 = *piVar1 - (int)unaff_SI;
    if (*piVar1 == 0) {
      func_0x0001fd71();
    }
    func_0x00015002();
    func_0x00015059();
    func_0x00014fb0();
    FUN_1000_774c();
    FUN_1000_774c();
  }
  func_0x0001c0c0();
  func_0x00012d1d();
  return;
}



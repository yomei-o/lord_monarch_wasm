/* 1000:054a */

/* WARNING: Instruction at (ram,0x0001057a) overlaps instruction at (ram,0x00010578)
    */

undefined4 FUN_1000_054a(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  long lVar2;
  char cVar3;
  undefined2 in_CX;
  int iVar4;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined2 in_stack_0000001c;
  undefined2 in_stack_00000020;
  
  *(undefined2 *)(in_BX + (int)unaff_SI) = in_DX;
  uVar6 = in(in_DX);
  *(undefined1 *)0x3bf2 = uVar6;
  *unaff_SI = 0x114;
  FUN_1000_4962();
  FUN_1000_7254();
  func_0x0001c5b9();
  cVar3 = FUN_1000_4b90();
  uVar5 = 0;
  uVar6 = cVar3 == '\0';
  if ((bool)uVar6) {
    FUN_1000_7c45();
    FUN_1000_49f4();
    FUN_1000_7254();
    FUN_1000_67c9();
    do {
      uVar7 = uVar6;
      func_0x00016be6();
      uVar8 = FUN_1000_6986();
      if ((bool)uVar5) {
        return uVar8;
      }
      lVar2 = (long)*(int *)(in_BX + 0x11a1) * 0x5520;
      uVar5 = (int)lVar2 != lVar2;
      if (!(bool)uVar5) {
        iVar4 = *(int *)0x3e82;
        while( true ) {
          iVar4 = iVar4 + 1;
          uVar6 = iVar4 == 0;
          func_0x00057176();
          func_0x00016c5a();
          if (!(bool)uVar6) break;
          *(char *)(unaff_BP + -0x41d7) = *(char *)(unaff_BP + -0x41d7) + (char)in_CX;
        }
        param_3._2_2_ = (undefined1 *)0x5f1c;
        break;
      }
      FUN_1000_6c5b();
      param_3._2_2_ = (undefined1 *)0x3bf3;
      uVar6 = 1;
    } while ((bool)uVar7);
  }
  for (iVar4 = 0x30; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar1 = param_3._2_2_;
    param_3._2_2_ = param_3._2_2_ + 1;
    *puVar1 = 0xff;
  }
  for (iVar4 = 0x90; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar1 = param_3._2_2_;
    param_3._2_2_ = param_3._2_2_ + 1;
    *puVar1 = 0;
  }
  FUN_1000_7526();
  FUN_1000_4946();
  FUN_1000_4b74();
  FUN_1000_74a3();
  return CONCAT22(in_stack_0000001c,in_stack_00000020);
}



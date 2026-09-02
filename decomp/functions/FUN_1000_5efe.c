/* 1000:5efe */

undefined4 __cdecl16near FUN_1000_5efe(void)

{
  uint in_AX;
  uint uVar1;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 uVar2;
  undefined1 uVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = &stack0xfff0 < (undefined1 *)0x2;
  uVar1 = in_AX;
  FUN_1000_6c3f();
  do {
    do {
      uVar3 = uVar2;
      *(undefined1 *)(unaff_SI + 8) = 0x42;
      FUN_1000_687e();
      uVar2 = 1;
    } while ((bool)uVar3);
    uVar3 = 0;
    FUN_1000_6f4b();
    FUN_1000_68a0();
    uVar2 = 1;
  } while ((bool)uVar3);
  uVar5 = uVar1 + 0x800;
  bVar4 = 0xf7ff < uVar1;
  do {
    do {
      uVar2 = bVar4;
      *(undefined1 *)(unaff_SI + 8) = 0x52;
      FUN_1000_687e();
      bVar4 = true;
    } while ((bool)uVar2);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    bVar4 = true;
  } while ((bool)uVar2);
  iVar6 = uVar5 + 0x800;
  bVar4 = 0xf7ff < uVar5;
  do {
    do {
      uVar2 = bVar4;
      *(undefined1 *)(unaff_SI + 8) = 0x47;
      FUN_1000_687e();
      bVar4 = true;
    } while ((bool)uVar2);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    bVar4 = true;
  } while ((bool)uVar2);
  uVar1 = iVar6 + 0x800;
  bVar4 = uVar1 < 0xb800;
  if (0xb800 < uVar1) {
    bVar4 = 0xdfff < uVar1;
    uVar1 = iVar6 + 0x2800;
  }
  do {
    do {
      uVar2 = bVar4;
      *(undefined1 *)(unaff_SI + 8) = 0x45;
      FUN_1000_687e(uVar1);
      bVar4 = true;
    } while ((bool)uVar2);
    FUN_1000_6f4b();
    FUN_1000_68a0();
    bVar4 = true;
  } while ((bool)uVar2);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:4658 */

undefined4 __cdecl16near FUN_1000_4658(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  bool bVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  bVar3 = false;
  FUN_1000_b4d8();
  if (!bVar3) {
    FUN_1000_4814();
    iVar2 = 0x10;
    do {
      FUN_1000_9a36();
      FUN_1000_9b34();
      bVar3 = false;
      if (((undefined *)&DAT_0000_d27e)[in_BX] == '\0') {
        iVar1 = FUN_1000_aac4();
        if (bVar3) break;
        uVar4 = *(uint *)(unaff_SI + 6) < (uint)(iVar1 * 2);
        uVar5 = *(uint *)(unaff_SI + 6) == iVar1 * 2;
        if ((bool)uVar4) break;
        FUN_1000_a61d();
        FUN_1000_ae9e();
        if (!(bool)uVar4) {
          *(undefined2 *)(unaff_SI + 8) = extraout_DX;
          FUN_1000_b78c();
          uVar4 = FUN_1000_c0bd();
          if (!(bool)uVar5) {
            *(undefined1 *)(unaff_SI + 0xb) = uVar4;
          }
          *(byte *)(unaff_SI + 10) = *(byte *)(unaff_SI + 10) & 0xd0 | 5;
          *(undefined1 *)(unaff_SI + 0xf) = 4;
          return CONCAT22(in_DX,in_AX);
        }
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return CONCAT22(in_DX,in_AX);
}



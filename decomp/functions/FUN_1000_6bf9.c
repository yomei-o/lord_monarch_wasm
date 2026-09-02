/* 1000:6bf9 */

undefined2 FUN_1000_6bf9(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  int extraout_DX;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  func_0x00014c23();
  do {
    puVar3 = (undefined2 *)(unaff_DI + 1);
    *unaff_DI = 0xff;
    for (iVar5 = extraout_DX; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar4 = puVar3;
      puVar3 = puVar3 + 1;
      *puVar4 = 0xffff;
    }
    *(undefined1 *)puVar3 = 0xff;
    unaff_DI = (undefined1 *)((int)puVar3 + unaff_BP + 1);
    in_BX = in_BX + -1;
  } while (in_BX != 0);
  *(undefined1 *)0xf566 = 0xff;
  pbVar1 = unaff_SI;
  bVar2 = *pbVar1;
  *pbVar1 = *pbVar1 - 0x25;
  return CONCAT11(0xf5,(0x24 < bVar2) + -0x18);
}



/* 1000:bcf4 */

undefined4 __cdecl16near FUN_1000_bcf4(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_DS;
  
  puVar6 = (undefined2 *)0x1200;
  puVar5 = (undefined2 *)&DAT_0000_d27e;
  iVar3 = 0x30;
  do {
    iVar4 = 0x30;
    do {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      uVar2 = 0x4000;
      if (0x2f < (byte)*puVar1) {
        uVar2 = 0xffff;
      }
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar1 = uVar2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return CONCAT22(in_DX,in_AX);
}



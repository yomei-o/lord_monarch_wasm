/* 1000:0296 */

undefined2 __cdecl16near FUN_1000_0296(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  int iVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  puVar4 = (undefined2 *)&DAT_0000_e47e;
  for (iVar2 = 0x900; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = 0;
  }
  pbVar3 = (byte *)&DAT_0000_c800;
  iVar2 = 0x40;
  do {
    if ((*pbVar3 & 0x80) == 0) {
      *(byte **)((undefined *)&DAT_0000_e47e + *(int *)(pbVar3 + 4)) = pbVar3;
    }
    pbVar3 = pbVar3 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return in_AX;
}



/* 1000:add0 */

undefined4 __cdecl16near FUN_1000_add0(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined2 in_DX;
  byte *pbVar2;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)&DAT_0000_c800;
  iVar1 = 0x40;
  do {
    if ((*pbVar2 & 0x80) != 0) break;
    pbVar2 = pbVar2 + 0x10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}



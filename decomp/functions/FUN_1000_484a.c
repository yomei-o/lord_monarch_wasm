/* 1000:484a */

undefined4 __cdecl16near FUN_1000_484a(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  uVar4 = FUN_1000_bcf4();
  pbVar3 = (byte *)&DAT_0000_c800;
  iVar2 = 0x40;
  bVar1 = *(byte *)0x3c00;
  do {
    if ((((*pbVar3 & 0x80) == 0) && (pbVar3[0xb] == 0xff)) &&
       ((pbVar3[10] == 0 || ((bVar1 != pbVar3[0xc] && (pbVar3[10] == 2)))))) {
      pbVar3[10] = 1;
    }
    pbVar3 = pbVar3 + 0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar4;
}



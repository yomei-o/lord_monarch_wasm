/* 1000:32cc */

void __cdecl16near FUN_1000_32cc(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined2 unaff_DS;
  
  *(undefined2 *)0xc52c = 0;
  iVar2 = (0x40U >> (*(byte *)0x3c02 & 0x1f)) - 1;
  pbVar3 = (undefined *)&DAT_0000_c800 + *(int *)0x3bec;
  while( true ) {
    bVar1 = *pbVar3;
    if (-1 < (char)bVar1) break;
    pbVar4 = pbVar3 + 0x1f0;
    if ((byte *)0xcbff < pbVar4) {
      pbVar4 = pbVar3 + -0x210;
    }
    iVar2 = iVar2 + -1;
    pbVar3 = pbVar4;
    if (iVar2 == 0) {
      *(undefined2 *)0x3bec = pbVar4 + 0x3800;
      return;
    }
  }
  *pbVar3 = bVar1 & 0xfe;
  if ((bVar1 & 2) != 0) {
    FUN_1000_493a();
    return;
  }
  if (pbVar3[0xc] != 4) {
    if ((pbVar3[10] & 0x20) != 0) {
      FUN_1000_3a67();
      return;
    }
    if ((pbVar3[10] & 0x10) == 0) {
      FUN_1000_383e();
      return;
    }
    FUN_1000_3608();
    return;
  }
  FUN_1000_3b86();
  return;
}



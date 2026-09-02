/* 1000:7141 */

/* WARNING: Removing unreachable block (ram,0x00017188) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near FUN_1000_7141(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  bool bVar6;
  
  *(undefined2 *)&DAT_0000_c4e6 = 0;
  FUN_1000_720b();
  iVar4 = 0xff;
  cVar3 = '\x01';
  do {
    out(0xec,cVar3);
    bVar1 = in(0xec);
    if ((bVar1 & 2) != 0) {
      _DAT_8000_0000 = _DAT_8000_0000 + -0x6928;
      out(0xec,0);
    }
    cVar3 = cVar3 + '\x01';
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0x1000;
  do {
    out(0xec,0);
    bVar1 = in(0xec);
    if (((bVar1 & 2) != 0) || ((bVar1 & 1) != 0)) break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  out(0x467,0);
  iVar4 = 4;
  bVar1 = 0;
  do {
    out(0x8e9,bVar1);
    iVar5 = -0x8000;
    do {
      bVar2 = in(0x8e9);
      bVar6 = (bVar2 & 1) != 0;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0 && bVar6);
    if (!bVar6) {
      out(0x8e1,0);
      _DAT_c000_0000 = _DAT_c000_0000 + -0x6928;
      iVar5 = 0x40;
      bVar2 = (byte)(bVar1 >> 1 | bVar1 << 7) >> 1 | (bVar1 >> 1) << 7;
      do {
        FUN_1000_720b(bVar2);
        bVar2 = bVar2 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    bVar1 = bVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



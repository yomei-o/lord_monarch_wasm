/* 1000:72d0 */

undefined4 __cdecl16near FUN_1000_72d0(void)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint in_AX;
  char cVar5;
  uint uVar4;
  int iVar6;
  byte bVar7;
  undefined2 in_DX;
  undefined2 *puVar8;
  undefined2 unaff_ES;
  
  cVar5 = (char)(in_AX >> 8);
  if (in_AX < 0x3021) {
    out(0xa1,(char)in_AX);
    out(0xa3,cVar5 + -0x20);
    puVar8 = (undefined2 *)0x3e50;
    bVar7 = 0;
    iVar6 = 0x10;
    do {
      out(0xa5,bVar7);
      uVar2 = in(0xa9);
      out(0xa5,bVar7 | 0x20);
      uVar3 = in(0xa9);
      uVar4 = CONCAT11(uVar3,uVar2) * 2 | CONCAT11(uVar3,uVar2);
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = CONCAT11((char)uVar4,(char)(uVar4 >> 8));
      bVar7 = bVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    out(0xa1,(char)in_AX);
    out(0xa3,cVar5 + -0x20);
    puVar8 = (undefined2 *)0x3e50;
    bVar7 = 0;
    iVar6 = 0x10;
    do {
      out(0xa5,bVar7);
      uVar2 = in(0xa9);
      out(0xa5,bVar7 | 0x20);
      uVar3 = in(0xa9);
      uVar4 = CONCAT11(uVar3,uVar2);
      uVar4 = (uint)(((ulong)~(uVar4 << 2 & uVar4) | 0x10000) >> 1) & uVar4 * 2 | uVar4;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar1 = CONCAT11((char)uVar4,(char)(uVar4 >> 8));
      bVar7 = bVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return CONCAT22(in_DX,in_AX);
}



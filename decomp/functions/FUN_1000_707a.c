/* 1000:707a */

uint __cdecl16near FUN_1000_707a(void)

{
  int iVar1;
  byte bVar3;
  uint uVar2;
  undefined1 uVar4;
  int in_BX;
  undefined2 unaff_DS;
  
  uVar2 = *(uint *)((undefined *)&DAT_0000_bdae + in_BX);
  bVar3 = (byte)(uVar2 >> 8);
  if (bVar3 < 0xa0) {
    if ((char)uVar2 != '\0') {
      out(0xec,(char)uVar2);
    }
  }
  else {
    iVar1 = (uVar2 & 0xff) * 4;
    out(0x8e9,(char)((uint)iVar1 >> 8));
    uVar4 = (undefined1)iVar1;
    uVar2 = CONCAT11(bVar3,uVar4);
    out(0x8e1,uVar4);
  }
  return uVar2 & 0xff00;
}



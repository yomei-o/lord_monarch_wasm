/* 1000:01b9 */

byte __cdecl16near FUN_1000_01b9(void)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  undefined *puVar4;
  uint extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 *puVar5;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  bool bVar6;
  
  bVar6 = false;
  if ((*(byte *)0x538 & 1) == 0) {
    FUN_1000_73f8();
    if (!bVar6) {
      out(0x188,7);
      FUN_1000_73f8();
      if (!bVar6) {
        bVar6 = 0xfffd < extraout_DX;
        out(extraout_DX + 2,0xbf);
        FUN_1000_73f8();
        if ((!bVar6) && (cVar2 = in(extraout_DX_00), cVar2 == -0x41)) {
          *(undefined2 *)0x3b3a = 1;
          out(0x188,0xe);
          cVar2 = in(0x18a);
          puVar5 = (undefined2 *)0x50;
          if (-1 < cVar2) {
            pbVar1 = (byte *)0x3b3c;
            *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
            puVar5 = (undefined2 *)0x54;
          }
          *puVar5 = 0xd52;
          puVar5[1] = unaff_CS;
          FUN_1000_14e8();
          FUN_1000_14c9();
          bVar3 = in(10);
          out(10,bVar3 & *(byte *)0x3b3c);
          return bVar3 & *(byte *)0x3b3c;
        }
      }
    }
  }
  *(undefined2 *)0x3b3a = 0;
  *(undefined2 *)0x20 = (undefined *)&DAT_0000_162b;
  *(undefined2 *)0x22 = unaff_CS;
  out(0x77,0x30);
  puVar4 = (undefined *)&DAT_0000_9fe8;
  if ((*(byte *)0x501 & 0x80) != 0) {
    puVar4 = (undefined *)&DAT_0000_81e8;
  }
  *(undefined2 *)0x3b4a = puVar4;
  out(0x71,(char)puVar4);
  out(0x71,(char)((uint)puVar4 >> 8));
  bVar3 = in(2);
  out(2,bVar3 & 0xfe);
  return bVar3 & 0xfe;
}



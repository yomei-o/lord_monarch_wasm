/* 1000:c5bb */

undefined2 __cdecl16near FUN_1000_c5bb(void)

{
  byte bVar1;
  undefined2 in_AX;
  undefined *puVar2;
  int unaff_SI;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x34b6 =
       *(undefined2 *)((undefined *)&DAT_0000_12ad + (*(byte *)(unaff_SI + 0xc) & 0xf) * 2);
  *(undefined2 *)0x34b8 = *(undefined2 *)(unaff_SI + 6);
  *(undefined2 *)0x34be = *(undefined2 *)(unaff_SI + 2);
  bVar1 = *(byte *)(unaff_SI + 10);
  puVar2 = (undefined *)&DAT_0000_1308;
  if ((bVar1 & 0x10) != 0) {
    puVar2 = (undefined *)&DAT_0000_1306;
  }
  *(undefined2 *)0x34bc = puVar2;
  *(uint *)0x34ba = bVar1 & 0xf;
  return in_AX;
}



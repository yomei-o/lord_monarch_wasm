/* 1000:ad56 */

undefined4 __cdecl16near FUN_1000_ad56(void)

{
  undefined *puVar1;
  undefined2 in_AX;
  undefined2 in_DX;
  byte bVar2;
  undefined *puVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  bVar2 = 0;
  puVar3 = (undefined *)&DAT_0000_ce74;
  do {
    puVar3[0x100] = *(undefined1 *)ZEXT24((undefined1 *)&DAT_0000_2d3d + (bVar2 & 0xf));
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = *(undefined1 *)ZEXT24((undefined1 *)&DAT_0000_2d3d + (bVar2 >> 4));
    bVar2 = bVar2 + 1;
  } while (bVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}



/* 1000:70a6 */

undefined2 __cdecl16near FUN_1000_70a6(void)

{
  undefined2 in_AX;
  int in_BX;
  undefined2 unaff_DS;
  
  if ((byte)((uint)*(undefined2 *)((undefined *)&DAT_0000_bdae + in_BX) >> 8) < 0xa0) {
    if ((char)*(undefined2 *)((undefined *)&DAT_0000_bdae + in_BX) != '\0') {
      out(0xec,0);
    }
  }
  return in_AX;
}



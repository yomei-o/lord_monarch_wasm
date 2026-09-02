/* 1000:5bd4 */

undefined2 __cdecl16near FUN_1000_5bd4(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if ((byte)(*(char *)((int)(undefined2 *)&DAT_0000_3be4 + 1) -
             *(char *)((int)(undefined2 *)&DAT_0000_3be2 + 1) << (*(byte *)0x3288 & 0x1f)) < 0x18) {
    FUN_1000_5c10();
  }
  else {
    FUN_1000_5c1b();
  }
  return in_AX;
}



/* 1000:5b6a */

undefined1 FUN_1000_5b6a(void)

{
  undefined2 in_BX;
  
  out(0x8e9,(char)((uint)in_BX >> 8));
  out(0x8e1,(char)in_BX);
  return 0;
}



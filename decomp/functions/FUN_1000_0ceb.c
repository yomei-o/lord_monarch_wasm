/* 1000:0ceb */

void __cdecl16near FUN_1000_0ceb(void)

{
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if (((*(byte *)0x3b3e & 1) == 0) && (*(char *)0x3b40 == '\0')) {
    *(undefined1 *)0x3b41 = 0x10;
    *(undefined1 *)0x3b40 = 0xff;
  }
  *(undefined2 *)0x3b44 = in_AX;
  return;
}



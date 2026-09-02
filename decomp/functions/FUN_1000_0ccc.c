/* 1000:0ccc */

void __cdecl16near FUN_1000_0ccc(void)

{
  undefined1 in_AL;
  undefined2 unaff_DS;
  
  if (((*(byte *)0x3b3e & 1) == 0) && (*(char *)0x3b40 == '\0')) {
    *(undefined1 *)0x3b41 = in_AL;
    *(undefined1 *)0x3b40 = 0xff;
  }
  return;
}



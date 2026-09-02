/* 1000:6e1a */

void FUN_1000_6e1a(void)

{
  int iVar1;
  undefined2 unaff_SS;
  
  iVar1 = 0xb;
  do {
    *(undefined1 *)0x32d3 = (char)*(undefined2 *)0x3e78;
    FUN_1000_6e3f();
    do {
    } while (*(char *)0x32d3 != '\0');
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}



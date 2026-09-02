/* 1000:740d */

void __cdecl16near FUN_1000_740d(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  if (*(char *)0x3b43 == '\0') {
    uVar1 = FUN_1000_7455();
    out(0x188,(char)uVar1);
    out(0x18a,(char)((uint)uVar1 >> 8));
  }
  return;
}



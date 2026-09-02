/* 1000:a731 */

undefined2 __cdecl16near FUN_1000_a731(void)

{
  int *piVar1;
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  if ((*(byte *)0x3be8 & ~(-2 << (*(byte *)0x3c02 & 0x1f))) == 0) {
    piVar1 = (int *)0x3bcc;
    *piVar1 = *piVar1 + 1;
    if (*piVar1 == 0) {
      *(undefined2 *)0x3bcc = 0xffff;
    }
    if (*(int *)0x3bca != 0) {
      *(int *)0x3bca = *(int *)0x3bca + -1;
    }
  }
  return in_AX;
}



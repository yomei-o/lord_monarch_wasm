/* 1000:c316 */

undefined2 __cdecl16near FUN_1000_c316(void)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 *in_BX;
  undefined2 unaff_DS;
  
  FUN_1000_9b34();
  cVar1 = *(char *)(in_BX + -0x16c1);
  if (((cVar1 == 'z') || (cVar1 == '{')) || ((byte)(cVar1 - 0x30U) < 0x30)) {
    *in_BX = 0x4000;
  }
  return in_AX;
}



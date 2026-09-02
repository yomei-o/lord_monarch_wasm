/* 1000:6ab8 */

void FUN_1000_6ab8(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}



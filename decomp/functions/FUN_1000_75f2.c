/* 1000:75f2 */

void FUN_1000_75f2(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}



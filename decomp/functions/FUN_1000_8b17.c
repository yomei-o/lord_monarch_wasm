/* 1000:8b17 */

void FUN_1000_8b17(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



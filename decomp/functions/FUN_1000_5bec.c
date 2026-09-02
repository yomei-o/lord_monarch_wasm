/* 1000:5bec */

void FUN_1000_5bec(void)

{
  char cVar1;
  byte in_DL;
  undefined2 *puVar2;
  undefined2 *unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)0x74c0 = *(byte *)0x74c0 | in_DL;
  puVar2 = (undefined2 *)&stack0xfffa;
  cVar1 = '\x14';
  do {
    unaff_BP = unaff_BP + -1;
    puVar2 = puVar2 + -1;
    *puVar2 = *unaff_BP;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  return;
}



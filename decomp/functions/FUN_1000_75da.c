/* 1000:75da */

undefined2 FUN_1000_75da(void)

{
  int in_CX;
  int in_BX;
  char *unaff_DI;
  char *pcVar1;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  unaff_DI[in_BX + 0x900] = unaff_DI[in_BX + 0x900] >> ((byte)in_CX & 0x1f);
  do {
    pcVar1 = unaff_DI + 1;
    if ((char)(*(char *)0x3c00 + '\x14') == *unaff_DI) break;
    unaff_DI = unaff_DI + 2;
    in_CX = in_CX + -1;
    pcVar1 = unaff_DI;
  } while (in_CX != 0);
  *(undefined2 *)0x3be4 =
       CONCAT11((char)(((uint)(pcVar1 + 0x2d81) >> 1) / 0x30),
                (char)(((uint)(pcVar1 + 0x2d81) >> 1) % 0x30));
  return in_stack_00000000;
}



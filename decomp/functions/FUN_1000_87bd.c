/* 1000:87bd */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_87bd(void)

{
  byte bVar1;
  uint in_AX;
  byte bVar2;
  int iVar3;
  int unaff_BP;
  int unaff_SI;
  undefined2 *puVar4;
  int unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & (byte)in_AX;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) ^ (byte)in_AX;
  *(char *)0x230 = *(char *)0x230 + -1;
  puVar4 = (undefined2 *)0x0;
  iVar3 = 0x900;
  do {
    bVar1 = (byte)in_AX;
    bVar2 = *(char *)(puVar4 + -0x16c1) - 8;
    in_AX = CONCAT11(bVar2,bVar1);
    if ((bVar2 < 8) && (in_AX = CONCAT11(bVar2,bVar1) & 0x3ff, bVar1 != (bVar2 & 3))) {
      *puVar4 = 0xffff;
    }
    bVar5 = (undefined2 *)0xfffd < puVar4;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(char *)0x2005 = (*(char *)0x2005 - (char)(in_AX >> 8)) - bVar5;
  *(undefined2 *)(unaff_CS + -2) = unaff_DS;
  *(uint *)(unaff_CS + -4) = in_AX;
  *(undefined2 *)(unaff_CS + -6) = 0;
  *(undefined2 *)(unaff_CS + -8) = 0x808;
  *(undefined2 *)(unaff_CS + -10) = 0x2003;
  *(int *)(unaff_CS + -0xc) = unaff_CS + -2;
  *(undefined2 *)(unaff_CS + -0xe) = 0xffff;
  *(undefined2 *)(unaff_CS + -0x10) = puVar4;
  *(undefined2 *)(unaff_CS + -0x12) = 2;
  *(undefined2 *)0x32bb = 0xffff;
  *(int *)0xc4ec = unaff_CS + -0x12;
  *(undefined2 *)0xc4ea = unaff_SS;
  *(undefined2 *)(unaff_CS + -0x14) = 0xffff;
  *(undefined2 *)(unaff_CS + -0x16) = 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



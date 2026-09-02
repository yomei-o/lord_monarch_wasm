/* 1000:32fe */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_32fe(void)

{
  int iVar1;
  byte in_AL;
  undefined2 uVar2;
  uint in_DX;
  uint uVar3;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_DS;
  char in_AF;
  
  iVar1 = *(int *)(in_BX + -0x1b82);
  if (iVar1 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(char *)(iVar1 + 3) = *(char *)(iVar1 + 3) << 1;
  *(byte *)(iVar1 + 0x2c) = *(byte *)(iVar1 + 0x2c) & (byte)(in_DX >> 8);
  if ((in_DX & 0x1010) == 0) {
LAB_1000_33cf:
    uVar3 = in_DX & 0xf0f;
    if (uVar3 != 0x303) {
      if ((char)(uVar3 >> 8) == '\x03') goto LAB_1000_33eb;
      if ((char)uVar3 == '\x03') goto LAB_1000_33f4;
    }
    if (*(uint *)(iVar1 + 6) <= *(uint *)(unaff_SI + 6)) {
LAB_1000_33f4:
      uVar2 = 0x558a;
      goto LAB_1000_3402;
    }
  }
  else {
    if ((in_DX & 0x10) == 0) goto LAB_1000_33f4;
    if ((in_DX & 0x1000) != 0) goto LAB_1000_33cf;
  }
LAB_1000_33eb:
  *(uint *)(iVar1 + 6) =
       CONCAT11(((in_AL & 0x66) == 0) << 6 | in_AF << 4 | ((POPCOUNT(in_AL & 0x66) & 1U) == 0) << 2,
                in_AL) & 0xff66 | 0x23a;
  uVar2 = FUN_1000_9f38();
LAB_1000_3402:
  return CONCAT22(unaff_DI,uVar2);
}



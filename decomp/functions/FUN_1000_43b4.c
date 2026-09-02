/* 1000:43b4 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_43b4(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte in_CL;
  uint in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar4;
  
  pbVar1 = (byte *)(in_BX + unaff_SI + 5);
  bVar2 = *pbVar1;
  *pbVar1 = bVar2 << 6 | (byte)(CONCAT11(in_CF,bVar2) >> 3);
  bVar2 = unaff_DI[unaff_BP];
  *unaff_DI = (char)in_DX;
  uVar3 = in_DX ^ 10;
  *(uint *)0x3292 = uVar3;
  bVar4 = CARRY1(in_CL,*(byte *)(CONCAT11((byte)((uint)in_BX >> 8) | bVar2,(char)in_BX) + uVar3));
  FUN_1000_462f(uVar3);
  if (!bVar4) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



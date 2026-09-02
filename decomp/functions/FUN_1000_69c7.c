/* 1000:69c7 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_69c7(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_DX;
  uint uVar4;
  uint *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  uVar2 = unaff_SI[0x20];
  uVar3 = unaff_SI[0x10];
  uVar1 = *unaff_SI;
  uVar4 = ~(uVar1 & uVar3 & uVar2 & in_DX);
  out(0x7e,(char)uVar1);
  out(0x7e,(char)uVar3);
  out(0x7e,(char)uVar2);
  out(0x7e,(char)in_DX);
  *unaff_DI = (char)uVar4;
  out(0x7e,(char)(uVar1 >> 8));
  out(0x7e,(char)(uVar3 >> 8));
  out(0x7e,(char)(uVar2 >> 8));
  out(0x7e,(char)(in_DX >> 8));
  unaff_DI[1] = (char)(uVar4 >> 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* 1000:7f36 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_7f36(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  byte in_DL;
  int extraout_DX;
  int iVar2;
  int unaff_BP;
  undefined1 *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  
  LOCK();
  uVar1 = *(undefined2 *)(unaff_SI + unaff_BP);
  *(undefined2 *)(unaff_SI + unaff_BP) = in_AX;
  UNLOCK();
  unaff_SI[unaff_BP] =
       (unaff_SI[unaff_BP] - (char)uVar1) -
       (CARRY1(in_DL,*(byte *)(unaff_DI + 0x55)) || CARRY1(in_DL + *(byte *)(unaff_DI + 0x55),in_CF)
       );
  unaff_SI[10] = 1;
  FUN_1000_7721();
  func_0x0001da68();
  FUN_1000_49f4();
  func_0x00013fd0();
  FUN_1000_6276();
  uVar1 = func_0x0001cfc0();
  *(undefined2 *)0x1667 = uVar1;
  func_0x00013ffd();
  iVar2 = extraout_DX;
  if ((*(uint *)0xc792 & 8) != 0) {
    iVar2 = extraout_DX + 1;
  }
  if (iVar2 + *(int *)(unaff_DI + -0x386c) == 2) {
    uVar1 = 2;
    if ((*(uint *)0xc792 & CONCAT11(-unaff_SI[-0x3866],0xfe)) != 0) {
      uVar1 = CONCAT11(199,'\x02' - *(char *)(unaff_DI + -0x386c));
      *(undefined1 *)(unaff_DI + 2) = 0xfe;
    }
    out(*unaff_SI,uVar1);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* 1000:2895 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_2895(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 in_AX;
  char cVar3;
  byte in_CL;
  int in_DX;
  char cVar4;
  int *in_BX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  int iVar6;
  byte *pbVar7;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  int iVar5;
  
  cVar3 = (char)((uint)in_AX >> 8);
  *in_BX = (*in_BX + -0x10) - (uint)(9 < (byte)in_AX);
  bVar2 = (byte)in_AX + 0x76;
  *(byte *)((int)in_BX + (int)unaff_SI) = *(byte *)((int)in_BX + (int)unaff_SI) + cVar3 + 1;
  out(0x10,bVar2);
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & in_CL;
  unaff_SI[unaff_BP + 0x4c3] = unaff_SI[unaff_BP + 0x4c3] | in_CL;
  *(byte *)(in_BX + -0x30) = *(byte *)(in_BX + -0x30) & bVar2;
  cVar4 = (char)in_BX + *(char *)(unaff_BP + -0x4aa6);
  iVar5 = CONCAT11((char)((uint)in_BX >> 8),cVar4);
  unaff_SI[iVar5] = unaff_SI[iVar5] - cVar3;
  iVar6 = unaff_DI + 1;
  uStack_14 = SUB21(unaff_SI,0);
  uStack_15 = (undefined1)((uint)iVar6 >> 8);
  pbVar7 = (byte *)(unaff_DI + 2);
  if ((SCARRY2(iVar6,1)) || (pbVar7 == (byte *)0x0 || iVar6 < -1)) {
    pbVar1 = unaff_SI + unaff_BP;
    *pbVar1 = *pbVar1 << 7 | *pbVar1 >> 1;
    pbVar7 = (byte *)(unaff_DI + 3);
    *(byte *)0x74c9 = *(byte *)0x74c9 ^ (byte)in_DX;
    *unaff_SI = *unaff_SI + 1;
  }
  else {
    unaff_SI = (byte *)CONCAT11(uStack_14,uStack_15);
    if (SCARRY2((int)&uStack_16,1)) {
      if (CARRY1(in_CL,*(byte *)(iVar5 + 0x2037))) {
        *(undefined1 *)0xc678 = *(undefined1 *)0xc672;
        unaff_SI[0x62] = 0x79;
        return;
      }
      *unaff_SI = *unaff_SI | in_CL + *(byte *)(iVar5 + 0x2037);
      bVar2 = unaff_SI[2];
      *(int *)(unaff_SI + iVar5 + -0x56) = *(int *)(unaff_SI + iVar5 + -0x56) + in_DX;
      *pbVar7 = bVar2;
      unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & bVar2;
      *unaff_SI = cVar4 + 1;
      return;
    }
  }
  *(byte **)unaff_SI = pbVar7 + *(int *)unaff_SI;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



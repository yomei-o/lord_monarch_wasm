/* 1000:573a */

int FUN_1000_573a(void)

{
  byte *pbVar1;
  char cVar2;
  int in_AX;
  char cVar3;
  byte extraout_AH;
  byte extraout_AH_00;
  int in_CX;
  int iVar4;
  byte bVar5;
  char cVar6;
  byte *unaff_SI;
  char *unaff_DI;
  byte *pbVar7;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool bVar8;
  
  if ((char)in_AX == *unaff_DI) {
    bVar5 = 0;
    cVar6 = '\x04';
    iVar4 = in_AX << 8;
    unaff_SI = (byte *)(unaff_DI + 1);
    do {
      pbVar7 = unaff_SI;
      unaff_SI = pbVar7 + 1;
      iVar4 = CONCAT11((char)((uint)iVar4 >> 8),*pbVar7);
      in_CX = 8;
      do {
        cVar3 = (char)((uint)iVar4 >> 8);
        cVar2 = (char)iVar4;
        if (cVar2 == cVar3) goto LAB_1000_5754;
        iVar4 = CONCAT11(cVar3,cVar2 << 1 | cVar2 < '\0');
        in_CX = in_CX + -1;
      } while (in_CX != 0);
      bVar5 = bVar5 - 1;
LAB_1000_5754:
      bVar5 = bVar5 + 1;
      cVar6 = cVar6 + -1;
    } while (cVar6 != '\0');
    bVar8 = bVar5 < 2;
    if (!bVar8) {
      unaff_SI = pbVar7 + 2;
      FUN_1000_578e();
      bVar5 = extraout_AH;
      if (bVar8) {
        bVar8 = true;
        FUN_1000_578e();
        bVar5 = extraout_AH_00;
        if (bVar8) goto LAB_1000_577c;
      }
      iVar4 = 0x40;
      pbVar7 = unaff_SI;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pbVar1 = pbVar7;
        pbVar7 = pbVar7 + 1;
      } while (bVar5 == *pbVar1);
      *unaff_SI = *unaff_SI ^ bVar5;
      return CONCAT11(bVar5,bVar5);
    }
  }
LAB_1000_577c:
  iVar4 = 0;
  do {
    pbVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    iVar4 = iVar4 + (uint)*pbVar1;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return iVar4;
}



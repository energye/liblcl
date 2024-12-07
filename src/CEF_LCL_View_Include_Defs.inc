procedure OnGetPreferredSize(const view: ICefView; var aResult : TCefSize); override;
procedure OnGetMinimumSize(const view: ICefView; var aResult : TCefSize); override;
procedure OnGetMaximumSize(const view: ICefView; var aResult : TCefSize); override;
procedure OnGetHeightForWidth(const view: ICefView; width: Integer; var aResult: Integer); override;
procedure OnParentViewChanged(const view: ICefView; added: boolean; const parent: ICefView); override;
procedure OnChildViewChanged(const view: ICefView; added: boolean; const child: ICefView); override;
procedure OnFocus(const view: ICefView); override;
procedure OnBlur(const view: ICefView); override;

uses graphABC;
type
  PianoButtonClass=class
    private
      PositionX, PositionY:integer;
      SizeW, SizeH:integer;
      ButtonColor:Color;
      Freak:integer;
    public
    
      procedure Draw();
      begin
        SetBrushColor(ButtonColor);
        fillRectangle(PositionX,PositionY,PositionX+SizeW,PositionY+Sizeh);
        drawRectangle(PositionX,PositionY,PositionX+SizeW,PositionY+Sizeh);
      end;
      procedure Play();
      begin
        system.Console.Beep(Freak, 500);
      end;
      function IsMouse(mx:integer; my:integer):boolean;
      begin 
        result:=(
          (mx>=PositionX)
          and
          (mx<=PositionX+SizeW)
          and
          (my>=PositionY)
          and
          (my<=PositionY+SizeH)
        );
      end;
      constructor Create(px:integer;py:integer;sw:integer;sh:integer;c:color;f:integer);
      begin
        PositionX:=px;
        PositionY:=py;
        SizeW:=sw;
        SizeH:=sh;
        Buttoncolor:=c;
        Freak:=f;
      end;
  end;
var
  Piano: array of PianoButtonClass;
  PianoSize:integer;
  
procedure onClick(mx:integer; my:integer; mb:integer);
begin
  for var i:=Piano.Length-1 downto 0 do
    if (Piano[i].IsMouse(mx,my)) then
    begin
      Piano[i].Play();
      break;
    end;
end;
begin
  onMouseDown:=onClick;
  PianoSize:=50;
  setLength(Piano,PianoSize+trunc((PianoSize/7)*5+1));
  var fw,fb:real;
  var ib:integer:=0;
  for var i:=0 to PianoSize-1 do
  begin
    fw:=440* power(2,(i-13)/12);
    fb:=fw+(440* power(2,(i-12)/12)-fw)/2;
    Piano[i]:=new PianoButtonClass(i*16,0,17,150,color.White,trunc(fw));
    if((i mod 7 <> 2) and (i mod 7 <> 5)) then
    begin
      Piano[ib+PianoSize]:=new PianoButtonClass(i*16+12,0,10,70,color.black,trunc(fb));
      ib+=1;
    end;
  end;
  for var i:=0 to Piano.Length-1 do
    Piano[i].Draw();
end.
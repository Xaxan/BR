 function WriteToFile() {
    
    set fso = CreateObject("Scripting.FileSystemObject");  
    set s = fso.CreateTextFile("C:\test.txt", True);
    s.writeline("HI");
    s.writeline("Bye");
    s.writeline("-----------------------------");
    s.Close();
 }
function CreateBookmarkLink(){
    var title = document.title;
    var url = window.location.href;
 
    if(window.sidebar && window.sidebar.addPanel){
        /* Mozilla Firefox Bookmark - works with opening in a side panel only � */
        window.sidebar.addPanel(title, url, "");
    }else if(window.opera && window.print) {
        /* Opera Hotlist */
        alert("Press Control + D to bookmark");
        return true;
    }else if(window.external){
        /* IE Favorite */
        try{
            window.external.AddFavorite(url, title);
        }catch(e){
                        alert("Press Control + D to bookmark");
                }            
    }else{
        /* Other */
        alert("Press Control + D to bookmark");
    }
}
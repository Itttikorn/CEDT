clearItems()
populatePersonDropdown()

function clearItems(){
    let tableBody = document.querySelector("#itemlist-table tbody");
	  
/* 
#itemlist-table tbody is a CSS selector that targets <tbody> that is a descendant of the HTML element with id = itemlist-table 

*/
	let num = tableBody.children.length
    for(let i=0; i < num; i++){
        tableBody.children[0].remove();
    }
}

function populatePersonDropdown(){
    let memberlist = document.getElementById("member-list")
    let dropbox = document.getElementById("person-select")
    for(let i=0;i<memberlist.children.length;i++){
        let newname = memberlist.children[i].innerHTML
        newoption = document.createElement("option")
        newoption.innerHTML = newname
        dropbox.appendChild(newoption)
    }
}

let addButton = document.querySelector("#addbutton")
addButton.addEventListener("click",clickAdd)

function clickAdd(event){
    let tableBody = document.querySelector("#itemlist-table tbody");
    let newtablerow = document.createElement("tr")
    newtablerow.setAttribute("class","item")
    let item = document.createElement("td")
    item.innerHTML = document.querySelector("#itemname-input").value;
    let uname = document.createElement("td")
    uname.innerHTML = document.querySelector("#person-select").value;
    let price = document.createElement("td")
    price.innerHTML = document.querySelector("#price-input").value;
    let tdbutton = document.createElement("td")
    let delbutton = document.createElement("button")
    delbutton.setAttribute("id","deletebutton")
    delbutton.innerHTML = "ลบ"
    delbutton.addEventListener("click",clickDelete)
    tdbutton.appendChild(delbutton)
    newtablerow.appendChild(item)
    newtablerow.appendChild(uname)
    newtablerow.appendChild(price)
    newtablerow.appendChild(tdbutton)
    tableBody.appendChild(newtablerow);
}

function clickDelete(event){
    let thisrow = event.target.closest("tr");
    thisrow.remove();
}



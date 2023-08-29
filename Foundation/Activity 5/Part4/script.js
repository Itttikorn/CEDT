let count=1;
const names = ["Ittikorn Pornchaipimolphant",
    "Metavin Karnjanarat",
    "Nakharin Somhom",
    "Sirichet Anankitphaiboon",
    "Sirawich Dechpak"
]

let droplist = document.getElementById("name-to-add");
for(let i=0;i<names.length;i++){
    let newname = document.createElement("option");
    newname.innerHTML = names[i];
    droplist.appendChild(newname);
}

function deletethisrow(elementParent){
    let thisrow = elementParent.parentNode.parentNode;
    thisrow.remove();
    count = count-1;
}

function add(){
    let table = document.getElementById("main-table");
    let itemname = document.getElementById("item-to-add").value;
    let personname = document.getElementById("name-to-add").value;
    let price = document.getElementById("price-to-add").value;
    let delbutton = document.createElement("button");
    delbutton.innerHTML = "ลบ";
    delbutton.setAttribute("onclick","deletethisrow(this)")
    delbutton.setAttribute("class","delete-row")
    let row = table.insertRow(count);
    let cell1 = row.insertCell(0);
    let cell2 = row.insertCell(1);
    let cell3 = row.insertCell(2);
    let cell4 = row.insertCell(3);

    count = count+1;

    cell1.innerHTML = itemname;
    cell2.innerHTML = personname;
    cell3.innerHTML = price;
    cell4.appendChild(delbutton)
}
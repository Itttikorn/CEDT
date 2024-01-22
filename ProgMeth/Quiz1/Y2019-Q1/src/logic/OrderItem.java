package logic;

import logic.Item;

public class OrderItem {
    private Item item;
    private int itemAmount;

    public OrderItem(Item item, int itemAmount) {
        this.item = item;
        setItemAmount(itemAmount);
    }

    public Item getItem() {
        return item;
    }

    public int getItemAmount() {
        return itemAmount;
    }

    public void setItemAmount(int itemAmount) {
        if (itemAmount < 0) itemAmount = 0;
        this.itemAmount = itemAmount;
    }

    public void increaseItemAmount(int amount){
        if(amount < 0) return;
        setItemAmount(getItemAmount()+amount);
    }

    public int calculateTotalPrice(){
        return getItemAmount()*getItem().getPricePerPiece();
    }
}

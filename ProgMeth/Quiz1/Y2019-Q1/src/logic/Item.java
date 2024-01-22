package logic;

public class Item {
    private String name;
    private int pricePerPiece;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPricePerPiece() {
        return pricePerPiece;
    }

    public void setPricePerPiece(int pricePerPiece) {
        if(pricePerPiece < 1) pricePerPiece = 1;
        this.pricePerPiece = pricePerPiece;
    }

    public Item(String name, int pricePerPiece) {
        setName(name);
        setPricePerPiece(pricePerPiece);
    }
}

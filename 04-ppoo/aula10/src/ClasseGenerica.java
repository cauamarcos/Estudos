public class ClasseGenerica<T> {
    private T objeto1;
    private T objeto2;
    private T objeto3;

    public ClasseGenerica (T objeto1, T objeto2, T objeto3) {
        this.objeto1 = objeto1;
        this.objeto2 = objeto2;
        this.objeto3 = objeto3;
    }
    public T getObjeto1() {return objeto1;}
    public T getObjeto2() {return objeto2;}
    public T getObjeto3() {return objeto3;}
    public void setObjeto1(T obj) {objeto1 = obj;}
    public void setObjeto2(T obj) {objeto2 = obj;}
    public void setObjeto3(T obj) {objeto3 = obj;}
}

public class NGPONG extends Person {
    public NGPONG(String _name, int _age) {
        /*super.Name = _name;
        super.Age = _age;*/
        super(_name, _age);
    }

    public void Programming() {
        System.out.println("My name is " + this.Name);
        System.out.println("I'm " + this.Age + " years old");
    }
}

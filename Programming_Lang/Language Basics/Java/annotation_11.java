//metadata or annotations
//not pure comments as provide info to compiler and thus changes exeecution
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

public class annotation_11 {
    //this annotation is linked with meth function
    //annotation member methods looks like fields
@myanno (str = "Anotation example", val = 100)
public static void meth()
{

}
}

//@ means annotation is being declared
//annotation consists solely of method declaration
//all annotation extends Annotation interface
//extends clause is not allowed
//even annocation can be annoted
@Retention(RetentionPolicy.RUNTIME)
@interface myanno {
    String str();
    int val();
}

//Annotation Retention Policy
// SOURCE, CLASS (default), RUNTIME
// Source: retained only in source file, discarded during compilation
// Class: retained in .class file. Discarded during JVM run time
// Runtime: .class as well as runtime


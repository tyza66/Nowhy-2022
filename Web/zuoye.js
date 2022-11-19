/**
 * Created by User on 2021/11/29.
 */
var students = [["Tom","1001","Web technology","70"],["Jerry","1002","Web technology","80"],["Tom","1003","Web technology","90"]];
var stuM = {
    name: "",
    num: "",
    course: "",
    grade: ""
};
var stu = new stuM();
for(var a=0;a<3;a++){
    stu[a].name = student[a][0];
    stu[a].num = student[a][1];
    stu[a].course = student[a][2];
    stu[a].grade = student[a][3];
}
document.write("<table border='1'>");
document.write("<tr>");
document.write("<td>stdname</td><td>stdNum</td><td>course</td><td>grade</td>");
for(var i=0;i<3;i++){
    document.write("<tr>");
    document.write("<td>"+stu[i].name+"</td>"+"<td>"+stu[i].num+"</td>"+"<td>"+stu[i].course+"</td>"+"<td>"+stu[i].grade+"</td>");
}
document.write("</table>");

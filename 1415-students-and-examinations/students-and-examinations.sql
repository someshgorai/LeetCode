# Write your MySQL query statement below
SELECT
    st.student_id,
    st.student_name,
    sb.subject_name,
    COUNT(e.student_id) AS attended_exams
FROM Students AS st
CROSS JOIN Subjects AS sb
LEFT JOIN Examinations AS e
    ON st.student_id = e.student_id
    AND sb.subject_name = e.subject_name
GROUP BY
    st.student_id,
    st.student_name,
    sb.subject_name
ORDER BY
    st.student_id,
    sb.subject_name;
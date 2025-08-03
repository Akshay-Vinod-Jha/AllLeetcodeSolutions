# Write your MySQL query statement below
select Signups.user_id as user_id , 
        case
            when total is null and totalconfirmed is null then 0
            else round(totalconfirmed/total,2)
        end as confirmation_rate
    from 
        Signups
        left join
        (
            select a.user_id , total , totalconfirmed
            from 
                (select user_id , count(*) as total 
            from Confirmations 
            group by user_id
            ) as a
                 join
                (select user_id , count(*) as totalconfirmed
            from Confirmations 
            where action = "confirmed"
            group by user_id) as b
            on a.user_id = b.user_id
        ) as c
    on Signups.user_id = c.user_id
    order by confirmation_rate





select
lt.user_id,
IFNULL(round(lt.confirmed_count/(lt.confirmed_count+rt.timeout_count),2),0) as confirmation_rate 
from 
(
    select 
    lt.user_id,
    IFNULL(confirmed_count,0) as confirmed_count
    from 
    Signups as lt
    left join
    (
        select 
    user_id,
    count(*) as confirmed_count
    from 
    Confirmations
    where action = 'confirmed'
group by user_id
    )  as rt
    on lt.user_id = rt.user_id
) as lt
join (
    select 
    lt.user_id,
    IFNULL(timeout_count,0) as timeout_count
    from 
    Signups as lt
    left join
    (
        select 
    user_id,
    count(*) as timeout_count
    from 
    Confirmations
    where action = 'timeout'
group by user_id
    )  as rt
    on lt.user_id = rt.user_id
) as rt

on lt.user_id = rt.user_id